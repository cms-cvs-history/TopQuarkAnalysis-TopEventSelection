import FWCore.ParameterSet.Config as cms

#-------------------------------------------------
# test cfg file for mva training for jet parton 
# association
#-------------------------------------------------
process = cms.Process("TEST")

## add message logger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'WARNINGS'

#-------------------------------------------------
# process configuration
#-------------------------------------------------

## define your trainingfile(s)
process.source = cms.Source("PoolSource",
     fileNames = cms.untracked.vstring(
       #please put your input files here
       #example: "file:/tmp/mrenz/CMSSW_2_2_4/src/job_1_TQAFLayer1_Output.root",
     ),
     skipEvents = cms.untracked.uint32(0)
)

## define maximal number of events to loop over
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

## configure process options
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(False)
)

## configure geometry
process.load("Configuration.StandardSequences.Geometry_cff")

## configure conditions
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('IDEAL_V9::All')

## load magnetic field
process.load("Configuration.StandardSequences.MagneticField_cff")


#-------------------------------------------------
# tqaf configuration
#-------------------------------------------------

## std sequence for tqaf layer1
#process.load("TopQuarkAnalysis.TopObjectProducers.tqafLayer1_full_cff")
#process.load("PhysicsTools.HepMCCandAlgos.genEventProcID_cfi")


## configure mva trainer
process.load("TopQuarkAnalysis.TopEventSelection.TraintreeSaver_cff")

## make trainer looper known to the process
from TopQuarkAnalysis.TopEventSelection.TraintreeSaver_cff import looper
process.looper = looper

#-------------------------------------------------
# process paths;
#-------------------------------------------------

## run tqafLayer1
#process.p0 = cms.Path(process.genEventProcID * process.tqafLayer1)
                      

## make mva training
process.p1 = cms.Path(process.saveTrainTree)
