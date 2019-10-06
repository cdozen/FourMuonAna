import FWCore.ParameterSet.Config as cms
process = cms.Process("Rootuple")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '94X_dataRun2_ReReco_EOY17_v2', '') #2017 ReReco

process.load("FWCore.MessageLogger.MessageLogger_cfi")
#process.MessageLogger.cerr.FwkReport.reportEvery = 500

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('root://cmsxrootd.fnal.gov/INPUTPATH1/INPUTFILE')
 #   fileNames = cms.untracked.vstring('root://cms-xrd-global.cern.ch/INPUTPATH1/INPUTFILE')
)


process.TFileService = cms.Service("TFileService",
        fileName = cms.string('Rootuple_NUMBER.root'),
)

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True))

process.load('DatasetsMixing.Onia.MixingRootupler_cfi')
process.p = cms.Path(process.rootuple)

process.rootuple.upsilon_mass = cms.double(9.4603)
process.rootuple.triggerCuts = cms.uint32(36)
process.rootuple.isMC = cms.bool(False)                 # is mc?
process.rootuple.onia_mass_cuts = cms.vdouble(0.1,500)    # you may need to adjust this
process.rootuple.SecondSource.fileNames = cms.untracked.vstring(
    'root://cmsxrootd.fnal.gov/MIXINPUTPATH/MIXFILEINPUT'
#    'root://cms-xrd-global.cern.ch/MIXINPUTPATH/INPUTFILE',
#    'root://cms-xrd-global.cern.ch/MIXINPUTPATH/INPUTFILE',
#    'root://cms-xrd-global.cern.ch/MIXINPUTPATH/INPUTFILE',
#    'root://cms-xrd-global.cern.ch/MIXINPUTPATH/INPUTFILE'
)
