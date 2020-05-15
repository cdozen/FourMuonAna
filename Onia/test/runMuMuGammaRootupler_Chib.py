import FWCore.ParameterSet.Config as cms
process = cms.Process("Rootuple")

process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
#process.load("Configuration.Geometry.GeometryIdeal_cff")
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_2016SeptRepro_v7', '')			#for 2016 Rereco

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'file:/eos/uscms/store/user/cdozen/FourMuon_Analysis/MuOnia/2016_v2/MuOnia/BPHSkim--Run2016D-07Aug17-v1/190620_113122/0000/BPHSkim_2016_100.root'
),
#'file:/uscms/home/muahmad/nobackup/Four_Mu_analysis/CMSSW_9_4_14_patch1/src/Final_Picked_merged_events.root'),
#eventsToProcess = cms.untracked.VEventRange('276653:755428809-276653:755428809')
)


process.TFileService = cms.Service("TFileService",
        fileName = cms.string('Rootuple_Run2016_v2.root'),
)

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load('FourMuonAna.Onia.MuMuGammaRootupler_cfi')
process.p = cms.Path(process.rootuple)

process.rootuple.upsilon_mass = cms.double(9.4630)
process.rootuple.triggerCuts = cms.uint32(36)
process.rootuple.isMC = cms.bool(False)                 # is mc?
process.rootuple.onia_mass_cuts = cms.vdouble(0.5,500)    # you may need to adjust this
#process.rootuple.SecondSource.fileNames = cms.untracked.vstring(
#    'file:/eos/cms/store/user/jblee/SpyFEDemulated234824.root'.
#     'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v4-Run2017F-17Nov2017-v1/180314_055941/0000/BPHSkim_425.root',
#	  'file:/eos/uscms/store/user/l1upgrades/Run2017/fourmuon/ZeroBias/BPHSkim-v4-Run2017F-17Nov2017-v1/180314_055941/0000/BPHSkim_426.root'
#	  )



