#include "FWCore/Framework/interface/MakerMacros.h"

#include "TopQuarkAnalysis/TopEventSelection/plugins/TtSemiLepSignalSelMVAComputer.h"
#include "TopQuarkAnalysis/TopEventSelection/plugins/TtSemiLepSignalSelMVATrainer.h"

#include "TopQuarkAnalysis/TopEventSelection/plugins/TtFullHadSignalSelMVAComputer.h"
#include "TopQuarkAnalysis/TopEventSelection/plugins/TtFullHadSignalSelMVATrainer.h"

// define mva modules
DEFINE_FWK_MODULE(TtSemiLepSignalSelMVAComputer);
DEFINE_FWK_MODULE(TtSemiLepSignalSelMVATrainer);

DEFINE_FWK_MODULE(TtFullHadSignalSelMVAComputer);
DEFINE_FWK_MODULE(TtFullHadSignalSelMVATrainer);

