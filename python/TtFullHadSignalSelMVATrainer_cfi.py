import FWCore.ParameterSet.Config as cms

#
# module to make mvaTraining for jet parton associations
#
buildTraintree = cms.EDAnalyzer("TtFullHadSignalSelMVATrainer",
    #input tags used in the example
    jets   = cms.InputTag("selectedLayer1Jets"),

    #three possibilities:
    # whatData=-1: in your training-file both, signal and background events are available
    # whatData=1: your training-file contains only signal events
    # whatData=0: your training-file contains only background events
    whatData = cms.int32(1),

    #maximum number of training events to be used
    # maxEv = -1: all events are used
    # for example maxEv = 5000: writes only the first 5000 events to the training tree
    maxEv = cms.int32(-1),
)
