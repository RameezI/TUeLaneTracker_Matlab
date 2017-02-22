MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/rameez/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for createTemplate" > createTemplate_mex.mki
echo "CC=$CC" >> createTemplate_mex.mki
echo "CFLAGS=$CFLAGS" >> createTemplate_mex.mki
echo "CLIBS=$CLIBS" >> createTemplate_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> createTemplate_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> createTemplate_mex.mki
echo "CXX=$CXX" >> createTemplate_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> createTemplate_mex.mki
echo "CXXLIBS=$CXXLIBS" >> createTemplate_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> createTemplate_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> createTemplate_mex.mki
echo "LDFLAGS=$LDFLAGS" >> createTemplate_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> createTemplate_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> createTemplate_mex.mki
echo "Arch=$Arch" >> createTemplate_mex.mki
echo "LD=$LD" >> createTemplate_mex.mki
echo OMPFLAGS= >> createTemplate_mex.mki
echo OMPLINKFLAGS= >> createTemplate_mex.mki
echo "EMC_COMPILER=gcc" >> createTemplate_mex.mki
echo "EMC_CONFIG=optim" >> createTemplate_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f createTemplate_mex.mk
