#!/bin/tcsh
echo "Starting job on " `date` #Date/time of start of job
echo "Running on: `uname -a`" #Condor job is running on this node
echo "System software: `cat /etc/redhat-release`" #Operating System on that node
source /cvmfs/cms.cern.ch/cmsset_default.csh  ## if a bash script, use .sh instead of .csh
### for case 1. EOS have the following line, otherwise remove this line in case 2.
xrdcp -s root://cmseos.fnal.gov//store/user/cdozen/CMSSW8029.tgz .
tar -xf CMSSW8029.tgz
rm CMSSW8029.tgz
setenv SCRAM_ARCH slc6_amd64_gcc630
cd CMSSW_8_0_29/src/
scramv1 b ProjectRename
eval `scramv1 runtime -csh` # cmsenv is an alias not on the workers
cd ${_CONDOR_SCRATCH_DIR}
cmsRun FILENAME
rm -rf CMSSW_8_0_29
