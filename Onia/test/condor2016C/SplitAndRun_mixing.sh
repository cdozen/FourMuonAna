#!/bin/bash
#cmsswDir="/store/user/cdozen/FourMuon_Analysis/NTuples/2017/ZeroBias/"
cmsswDir="/uscms_data/d3/cdozen/CMSSW_9_4_2/src/"
#cmsswDir="/uscms_data/d3/lpcbphy/zhenhu/Upsilon/fourmuon/CMSSW_9_4_0/src/"
inputFiles=""
inputFiles2=""

myeospath1="/store/user/muahmad/FourMuon_Analysis/MuOnia_v3/2017_v2/MuOnia/BPHSkim--Run2017F-17Nov2017-v1/190611_021142/0000"
#myeospath1="/store/user/muahmad/FourMuon_Analysis/MuOnia/2017_v2/MuOnia/BPHSkim--Run2017B-17Nov2017-v1/190609_091355/0000/"
myeospath2="/store/user/muahmad/FourMuon_Analysis/MiniBias/2017_v2/ZeroBias/BPHSkim--Run2017B-17Nov2017-v1/190609_091136/0000"
#myeospath1="/store/group/l1upgrades/Run2017/fourmuon/MuOnia/BPHSkim-v4-Run2017B-17Nov2017-v1/180314_061950/0000/"
#myeospath2="/store/group/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v6-Run2017B-17Nov2017-v1/180321_072905/0000/"

j=0
files2=(`ls /eos/uscms${myeospath2} | grep root`)
for files in `ls /eos/uscms${myeospath1} | grep root`
do 
	inputFiles2=${files2[j]};
	inputFiles=$files;
	echo $inputFiles;
	echo $inputFiles2;
	jobNb=${j};
	let j=${j}+1;
	#anaHeader="myntuple_${jobNb}.h";
	#anaCScript="myntuple_${jobNb}.C";
	jobCScript="runMixingRootupler_${jobNb}.py";
	scriptName="Run_${jobNb}.csh";
	condorScriptName="runOnCondor_${jobNb}";
	#cat myntuple.h | sed "s/NUMBER/${jobNb}/g" > ${anaHeader};
	#cat myntuple.C | sed "s/NUMBER/${jobNb}/g" > ${anaCScript};
	cat runMixingRootupler.py | sed "s:INPUTPATH1:${myeospath1}:" | sed "s-INPUTFILE-${inputFiles}-" | sed "s/NUMBER/${jobNb}/g" | sed "s:MIXINPUTPATH:${myeospath2}:" | sed "s-MIXFILEINPUT-${inputFiles2}-" > ${jobCScript} ;
	#cat runMixingRootupler.py | sed "s:INPUTPATH1:${myeospath1}:" | sed "s-INPUTFILE-${inputFiles}-" | sed "s/NUMBER/${jobNb}/g" | sed "s:MIXINPUTPATH:${myeospath2}:" > ${jobCScript} ;
	cat Run.csh | sed "s-FILENAME-${jobCScript}-" > ${scriptName};
	chmod +x ${scriptName}
	cat runOnCondor | sed "s/SCRIPT/${scriptName}/" | sed "s/JOBC/${jobCScript}/" > ${condorScriptName}
	condor_submit ${condorScriptName}
done
