%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%%
%% quick lane labe tool (only for straight labes)
%%
%%
function [] = lanelabel()


global posLeft;
global posRight;
global linPart;
global vp1;
global vp2;
global DATASET;
global NAME;
    
    %% TUE
    START = 20;
    START = 42801;
    DATASET = '/data2/datasets/binocular/prius/images';
%     DATASET = '/media/gijs/51581ef4-87a3-4aa5-834e-2c9a1f8321ed';
    
    
    %% where to start and what step size    
    STEP  = 30;

    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    %% create the label dirs %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%
    mkdir([DATASET,'/labels/training']);
    mkdir([DATASET,'/labels/testing']);
    mkdir([DATASET,'/labels/mining']);

    
    %%%%%%%%%%%%%%%%%%%%
    %% get all images %%
    %%%%%%%%%%%%%%%%%%%%
    DATASET
    files = dir([DATASET,'/images/*.png']);
    if 0 == size(files,1)
        files = dir([DATASET,'/images/*.ppm']);        
    end
    nframes = size(files,1)
    

    %%%%%%%%%%%%%%%%%%%
    %% for each file %%
    %%%%%%%%%%%%%%%%%%%
    nf = START;
    while 0 < nf

        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% load the image and resize %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        nf
        NAME     = files(nf).name;
        IMG     = imread( [DATASET,'/images/',NAME]);
        imsz    = size(IMG);
        
        %% already an RGB image
        if size(imsz, 2) == 3        
            RGB     = imresize( IMG, [480 640] );
            RGB     = im2double(RGB);
            
        %% probably raw Bumblebee frame
        else
            
           %% cut off top part
           IMG = IMG(1:imsz(1)/2,:);
           %% demosaic
           RGB = demosaic( IMG, 'grbg'); 
           RGB = imresize( RGB, [480 640] );
           RGB = im2double(RGB);
        end
            
        
        %%%%%%%%%%%%%%%%%%%%%%%%
        %% make vp plot empty %%
        %%%%%%%%%%%%%%%%%%%%%%%%
        vp1 = []; vp2 = [];
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% convert to HSV and apply historgram eq. %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        HSV        = rgb2hsv(RGB);
%         HSV(:,:,3) = histeq( HSV(:,:,3) );
        
        
        %%%%%%%%%%%%%%%%%
        %% back ro RGB %%
        %%%%%%%%%%%%%%%%%
        RGB = hsv2rgb(HSV);
           
        
        %%%%%%%%%%%%%%%%%%%
        %% default lines %%
        %%%%%%%%%%%%%%%%%%%
        if nf == START
            posLeft  = [220 300; 340 240];
            posRight = [420 340; 340 240];
            linPart  = 300;
        end
        
        %%%%%%%%%%%%%%%%%%%%%%%
        %% load if it exists %%
        %%%%%%%%%%%%%%%%%%%%%%%
        fileName = [DATASET,'/labels/training/',NAME(1:end-3),'txt']
        if exist( fileName, 'file' )
           
            
           %%%%%%%%%%
           %% load %%
           %%%%%%%%%%
           fid = fopen( fileName,'r');
           data = fscanf(fid,'%i %i %i %i %i %i %i %i\n');
           fclose(fid);
           
           
           %%%%%%%%%%%%%
           %% correct %%
           %%%%%%%%%%%%%
           if isequal( size(data), [9 1] )
               posLeft  = reshape(data(1:4),2,2); 
               posRight = reshape(data(5:8),2,2);
               linPart  = data(9);
           end
        end
        
        
        %%%%%%%%%%%%%%%%%%%%%%
        %% start the figure %%
        %%%%%%%%%%%%%%%%%%%%%%
        h = figure(1);
        clf
        imshow(RGB)
        axis([1 640 1 480]);
        hold on
        
        
        %%%%%%%%%%%%%%%%%
        %% draw the vp %%
        %%%%%%%%%%%%%%%%%
        computeVP( posLeft, posRight, 0 );
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %% draw the dragable line %%
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%
        left  = imline( gca, posLeft(1,:),  posLeft(2,:)  );
        right = imline( gca, posRight(1,:), posRight(2,:) );
        lin   = imline( gca, [1 640], [linPart linPart] );
        
        
        %%%%%%%%%%%%%%%%%%%%%%%%%
        %% setup the callbacks %%
        %%%%%%%%%%%%%%%%%%%%%%%%%
        apiLeft  = iptgetapi(left);
        apiRight = iptgetapi(right); 
        fcn = makeConstrainToRectFcn('imline',get(gca,'XLim'),get(gca,'YLim'));
        apiLeft.setPositionConstraintFcn(fcn);
        apiRight.setPositionConstraintFcn(fcn);
        apiLeft.addNewPositionCallback(  @(pos) computeVPLeft(pos) );
        apiRight.addNewPositionCallback( @(pos) computeVPRight(pos) );
        setPositionConstraintFcn( lin, @(pos) setLinPart(pos) );
        
        %%%%%%%%%%%%%%%%%%%%%%%%
        %% wait for key press %%
        %%%%%%%%%%%%%%%%%%%%%%%%
        while 1
        
            %%%%%%%%%%%%%%%%%%%%%%%%
            %% get the user input %%
            %%%%%%%%%%%%%%%%%%%%%%%%
            w = waitforbuttonpress;
            if w ~= 0
                button = uint16(get(h,'CurrentCharacter'));

                %% backward
                if button == 28
                    nf = nf - STEP;
                    if nf < 1
                        nf = 1;
                    end
                    
                    break
                    
                %% forward    
                elseif button == 29
                    nf = nf + STEP;
                    if nframes < nf
                       nf = nframes;
                    end
                    break
                    
                %% q
                elseif button == 113
                    nf = 0;
                    break;
                    
                end
            end
            
            %%%%%%%%%%%%%%%%
            %% wait a sec %%
            %%%%%%%%%%%%%%%%
            pause(0.25)
            
        end
        
    end
    
    %%%%%%%%%%%%%%%%%%%%%%
    %% close the figure %%
    %%%%%%%%%%%%%%%%%%%%%%
    close all

end



%%
%% compute the vp and save
%%
function [pos] = setLinPart( pos )
 
   global posLeft;
   global posRight;
   global linPart;
   
   %% check
   if pos(1,2) == pos(2,2)
      linPart = pos(1,2);
   end
   pos = [1 linPart; 640 linPart];
   computeVP( posLeft, posRight, 1 );
   
end



%%
%% compute the vp and save
%%
function [vp] = computeVP( posLeft, posRight, save )
 
    global vp1
    global vp2
    global linPart;
    global DATASET;
    global NAME;
    
    %% line params
    xLeft      = posLeft(1,1);
    yLeft      = posLeft(2,1);
    xRight     = posRight(1,1);
    yRight     = posRight(2,1);
    slopeLeft  = ( posLeft(2,2)  - posLeft(2,1)  ) /  (posLeft(1,2)  - posLeft(1,1)  );
    slopeRight = ( posRight(2,2) - posRight(2,1) ) /  (posRight(1,2) - posRight(1,1) );
    
    %% compute intersection
    x = (yRight-yLeft+slopeLeft*xLeft-slopeRight*xRight) / (slopeLeft-slopeRight);
    y = slopeLeft  * (x-xLeft)  + yRight;
    y = slopeRight * (x-xRight) + yRight;
    
    %% assign vp
    vp = [x;y];
    
    %% delte old ones
    if ~isempty(vp1)
        delete(vp1)
        delete(vp2)
    end
    
    %% draw new ones
    vp1 = plot( [vp(1)-50 vp(1)+50], [vp(2) vp(2)], 'r' );
    vp2 = plot( [vp(1) vp(1)], [vp(2)-50 vp(2)+50], 'r' );
    
    %% save to file
    if save
        fileName = [DATASET,'/labels/training/',NAME(1:end-3),'txt'];
        fid = fopen( fileName,'w');
        fprintf( fid, '%i %i %i %i %i %i %i %i %i\n', round([posLeft(:); posRight(:); linPart]) );
        fclose(fid); 
    end
    
end



%%
%% update the left lane
%%
function [] = computeVPLeft( pos )

    %% update and recompute vp
    global posLeft;
    global posRight;
    posLeft = pos';
    computeVP( posLeft, posRight, 1 );
    
end



%%
%% update the right lane
%%
function [] = computeVPRight( pos )

    %% update and recompute vp
    global posLeft;
    global posRight;
    posRight = pos';
    computeVP( posLeft, posRight, 1 );

end
