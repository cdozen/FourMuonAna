#!/bin/bash
#cmsswDir="/store/user/cdozen/FourMuon_Analysis/NTuples/2017/ZeroBias/"
cmsswDir="/uscms_data/d3/cdozen/CMSSW_8_0_29/src/"
#cmsswDir="/uscms_data/d3/lpcbphy/zhenhu/Upsilon/fourmuon/CMSSW_9_4_0/src/"
inputFiles=""

myeospath1="/store/user/cdozen/FourMuon_Analysis/MuOnia/2016_v2/MuOnia/BPHSkim--Run2016G-07Aug17-v2/190620_113209/0000"
#myeospath2="/store/user/muahmad/FourMuon_Analysis/MiniBias/2017_v2/ZeroBias/BPHSkim--Run2017B-17Nov2017-v1/190609_091136/0000"

j=0
for files in `ls /eos/uscms${myeospath1} | grep root`
do 
	inputFiles=$files;
	echo $inputFiles;
	jobNb=${j};
	let j=${j}+1;
	#anaHeader="myntuple_${jobNb}.h";
	#anaCScript="myntuple_${jobNb}.C";
	jobCScript="runMuOniaRootupler_${jobNb}.py";
	#jobCScript="runMixingRootupler_${jobNb}.py";
	scriptName="Run_${jobNb}.csh";
	condorScriptName="runOnCondor_${jobNb}";
	#cat myntuple.h | sed "s/NUMBER/${jobNb}/g" > ${anaHeader};
	#cat myntuple.C | sed "s/NUMBER/${jobNb}/g" > ${anaCScript};
	cat runMuOniaRootupler.py | sed "s:INPUTPATH1:${myeospath1}:" | sed "s-INPUTFILE-${inputFiles}-" | sed "s/NUMBER/${jobNb}/g" > ${jobCScript} ;
	#cat runMixingRootupler.py | sed "s:INPUTPATH1:${myeospath1}:" | sed "s-INPUTFILE-${inputFiles}-" | sed "s/NUMBER/${jobNb}/g" | sed "s:MIXINPUTPATH:${myeospath2}:" > ${jobCScript} ;
	cat Run.csh | sed "s-FILENAME-${jobCScript}-" > ${scriptName};
	chmod +x ${scriptName}
	cat runOnCondor | sed "s/SCRIPT/${scriptName}/" | sed "s/JOBC/${jobCScript}/" > ${condorScriptName}
	condor_submit ${condorScriptName}
done
