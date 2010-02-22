#ifndef TtFullHadSignalSelMVAComputer_h
#define TtFullHadSignalSelMVAComputer_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "PhysicsTools/MVAComputer/interface/HelperMacros.h"
#include "PhysicsTools/MVAComputer/interface/MVAComputerCache.h"

#include "DataFormats/Math/interface/LorentzVector.h"

#ifndef TtFullHadSignalSelMVARcd_defined  // to avoid conflicts with the TopFullHadLepSignalSelMVATrainer
#define TtFullHadSignalSelMVARcd_defined
MVA_COMPUTER_CONTAINER_DEFINE(TtFullHadSignalSelMVA);  // defines TopFullHadLepSignalSelMVARcd
#endif

class TtFullHadSignalSelMVAComputer : public edm::EDProducer {

 public:
  
  explicit TtFullHadSignalSelMVAComputer(const edm::ParameterSet&);
  ~TtFullHadSignalSelMVAComputer();
  
 private:

  virtual void beginJob();
  virtual void produce(edm::Event& evt, const edm::EventSetup& setup);
  virtual void endJob();

  double DeltaPhi(math::XYZTLorentzVector v1, math::XYZTLorentzVector v2);
  double DeltaR(math::XYZTLorentzVector v1, math::XYZTLorentzVector v2);

  edm::InputTag muons_;
  edm::InputTag jets_;
  edm::InputTag METs_;
  edm::InputTag electrons_;

  PhysicsTools::MVAComputerCache mvaComputer;

  double DiscSel;
  
};

#endif
