import FWCore.ParameterSet.Config as cms

#-------------------------------------------------
# test cfg file for mva training for jet parton 
# association
#-------------------------------------------------
process = cms.Process("TEST")

## add message logger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.threshold = 'INFO'

#-------------------------------------------------
# process configuration
#-------------------------------------------------

## define input
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
      'file:/storage/4/jkiefer/RelVal/04D2EB26-1861-DD11-8B21-001731A2845B.root',
      'file:/storage/4/jkiefer/RelVal/3620258E-1561-DD11-8532-0018F3D09700.root',
      'file:/storage/4/jkiefer/RelVal/2E7D553F-1661-DD11-950A-003048767653.root',
      'file:/storage/4/jkiefer/RelVal/36324959-A160-DD11-BB4B-000423D99BF2.root',
      'file:/storage/4/jkiefer/RelVal/08CA1B5E-1961-DD11-AABD-003048767EE7.root',
      'file:/storage/4/jkiefer/RelVal/381F1D8D-1861-DD11-A1FB-001A928116FA.root',
      'file:/storage/4/jkiefer/RelVal/14F7E282-1761-DD11-A114-001A92971B4C.root',
      'file:/storage/4/jkiefer/RelVal/1A773E5E-A160-DD11-81E8-001617C3B78C.root',
      'file:/storage/4/jkiefer/RelVal/3C03B69E-1761-DD11-96EE-001731AF67C5.root',
      'file:/storage/4/jkiefer/RelVal/1AABF3C1-A460-DD11-888C-001617E30D40.root',
      'file:/storage/4/jkiefer/RelVal/202BB34D-A160-DD11-B602-00161757BF42.root',
      'file:/storage/4/jkiefer/RelVal/22D6BF8B-1761-DD11-BC60-001A92810AF2.root',
      'file:/storage/4/jkiefer/RelVal/266AEE4A-A160-DD11-899F-0019DB29C620.root',
      'file:/storage/4/jkiefer/RelVal/2ADCDD72-1861-DD11-81C7-001A928116C4.root',
      'file:/storage/4/jkiefer/RelVal/2ED71580-1561-DD11-9E41-003048767ECF.root'
    )
)

## define maximal number of events to loop over
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

## configure process options
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(False)
)

## configure geometry
process.load("Configuration.StandardSequences.Geometry_cff")

## configure conditions
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.GlobalTag.globaltag = cms.string('STARTUP_V4::All')

## load magnetic field
process.load("Configuration.StandardSequences.MagneticField_cff")


#-------------------------------------------------
# tqaf configuration
#-------------------------------------------------

## std sequence for tqaf layer1
process.load("TopQuarkAnalysis.TopObjectProducers.tqafLayer1_full_cff")

## std sequence for ttGenEvent
process.load("TopQuarkAnalysis.TopEventProducers.sequences.ttGenEvent_cff")

## configure ttDecaySelection
process.load("TopQuarkAnalysis.TopEventProducers.producers.TtDecaySelection_cfi")
process.ttDecaySelection.channel_1 = [0, 1, 0]

## configure jet parton matching
#process.load("TopQuarkAnalysis.TopTools.TtSemiEvtJetPartonMatch_cfi")

## configure mva trainer
process.load("TopQuarkAnalysis.TopEventSelection.TtSemiLepSignalSelMVATrainer_Muons_cff")

## make trainer looper known to the process
from TopQuarkAnalysis.TopEventSelection.TtSemiLepSignalSelMVATrainer_Muons_cff import looper
process.looper = looper

#-------------------------------------------------
# process paths;
#-------------------------------------------------

## make jet parton match
process.p0 = cms.Path(process.tqafLayer1 *
                      process.makeGenEvt *
                      process.ttDecaySelection #*
                      #process.ttSemiJetPartonMatch
                      )

## make mva training
process.p1 = cms.Path(process.makeMVATraining)
