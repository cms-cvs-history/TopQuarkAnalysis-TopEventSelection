import FWCore.ParameterSet.Config as cms

#
# module to make the mvaComputer
#
findTtSemiLepSignalSelMVA = cms.EDProducer("TtSemiLepSignalSelMVAComputer",
    jets   = cms.InputTag("layer1Jets"),
    muons  = cms.InputTag("selectedLayer1Muons"),
    mets   = cms.InputTag("selectedLayer1METs"),
    elecs  = cms.InputTag("selectedLayer1Electrons")
)
