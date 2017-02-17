MATLAB="/usr/local/MATLAB/R2016b"
Arch=glnxa64
ENTRYPOINT=mexFunction
MAPFILE=$ENTRYPOINT'.map'
PREFDIR="/home/rameez/.matlab/R2016b"
OPTSFILE_NAME="./setEnv.sh"
. $OPTSFILE_NAME
COMPILER=$CC
. $OPTSFILE_NAME
echo "# Make settings for run_Init_State" > run_Init_State_mex.mki
echo "CC=$CC" >> run_Init_State_mex.mki
echo "CFLAGS=$CFLAGS" >> run_Init_State_mex.mki
echo "CLIBS=$CLIBS" >> run_Init_State_mex.mki
echo "COPTIMFLAGS=$COPTIMFLAGS" >> run_Init_State_mex.mki
echo "CDEBUGFLAGS=$CDEBUGFLAGS" >> run_Init_State_mex.mki
echo "CXX=$CXX" >> run_Init_State_mex.mki
echo "CXXFLAGS=$CXXFLAGS" >> run_Init_State_mex.mki
echo "CXXLIBS=$CXXLIBS" >> run_Init_State_mex.mki
echo "CXXOPTIMFLAGS=$CXXOPTIMFLAGS" >> run_Init_State_mex.mki
echo "CXXDEBUGFLAGS=$CXXDEBUGFLAGS" >> run_Init_State_mex.mki
echo "LDFLAGS=$LDFLAGS" >> run_Init_State_mex.mki
echo "LDOPTIMFLAGS=$LDOPTIMFLAGS" >> run_Init_State_mex.mki
echo "LDDEBUGFLAGS=$LDDEBUGFLAGS" >> run_Init_State_mex.mki
echo "Arch=$Arch" >> run_Init_State_mex.mki
echo "LD=$LD" >> run_Init_State_mex.mki
echo OMPFLAGS= >> run_Init_State_mex.mki
echo OMPLINKFLAGS= >> run_Init_State_mex.mki
echo "EMC_COMPILER=gcc" >> run_Init_State_mex.mki
echo "EMC_CONFIG=optim" >> run_Init_State_mex.mki
"/usr/local/MATLAB/R2016b/bin/glnxa64/gmake" -B -f run_Init_State_mex.mk
