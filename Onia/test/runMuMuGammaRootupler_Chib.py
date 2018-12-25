import FWCore.ParameterSet.Config as cms
process = cms.Process("Rootuple")

process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_Prompt_v4', '')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#'file:/eos/uscms/store/user/lpcmuon/fourmuonMC/H0ToUps1SMuMu_m18p5_TuneCUEP8M1_13TeV-pythia8/BPHSkim-v10/180308_232212/0000/BPHSkim_1.root',
'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/MuOnia/BPHSkim-v4-Run2017B-17Nov2017-v1/180314_061950/0000/BPHSkim_12.root'
#'file:/eos/uscms/store/user/l1upgrades/Run2018/fourmuon/MuOnia/BPHSkim-v1-Run2018A-PromptReco-v1/180830_190554/0000/BPHSkim_100.root'
	 )
)


process.TFileService = cms.Service("TFileService",
        fileName = cms.string('Rootuple.root'),
)

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load('MuMuGammaAna.Onia.MuMuGammaRootupler_cfi')
process.p = cms.Path(process.rootuple)

process.rootuple.upsilon_mass = cms.double(9.4603)
process.rootuple.triggerCuts = cms.uint32(36)
process.rootuple.isMC = cms.bool(False)                 # is mc?
process.rootuple.onia_mass_cuts = cms.vdouble(0.1,500)    # you may need to adjust this

#process.rootuple.SecondSource.fileNames = cms.untracked.vstring(
#    'file:/eos/cms/store/user/jblee/SpyFEDemulated234824.root'.
#     'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v4-Run2017F-17Nov2017-v1/180314_055941/0000/BPHSkim_425.root',
#	  'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v4-Run2017F-17Nov2017-v1/180314_055941/0000/BPHSkim_426.root'
#	  )



