#include "TopQuarkAnalysis/TopEventSelection/interface/TtFullHadSignalSel.h"
#include "TVector3.h"

TtFullHadSignalSel::TtFullHadSignalSel():
  pt1_(-1.), pt2_(-1.), pt3_(-1.), pt4_(-1.), pt5_(-1.), pt6_(-1.)
{
}

std::vector<math::XYZVector> makeVecForEventShape(std::vector<pat::Jet> jets, double scale = 1.) {
  std::vector<math::XYZVector> p;
  unsigned int i=1;
  for (std::vector<pat::Jet>::const_iterator jet = jets.begin(); jet != jets.end(); ++jet) {
    math::XYZVector Vjet(jet->px() * scale, jet->py() * scale, jet->pz() * scale);
    p.push_back(Vjet);
    ++i;
    if(i==6) break;
  }
  return p;
}

TtFullHadSignalSel::TtFullHadSignalSel(const std::vector<pat::Jet>& jets)
{

  H_      = 0;
  Ht_     = 0;
  Ht123_  = 0;
  Ht3jet_ = 0;
  Et56_   = 0;
  sqrt_s_ = 0;
  M3_     = 0;
  
  TCHP_Bjets_ = 0;
  SSV_Bjets_  = 0;
  CSV_Bjets_  = 0;
  SM_Bjets_   = 0;

  jet1_etaetaMoment_ = 0;
  jet2_etaetaMoment_ = 0;
  jet3_etaetaMoment_ = 0;
  jet4_etaetaMoment_ = 0;
  jet5_etaetaMoment_ = 0;
  jet6_etaetaMoment_ = 0;
  jet1_etaphiMoment_ = 0;
  jet2_etaphiMoment_ = 0;
  jet3_etaphiMoment_ = 0;
  jet4_etaphiMoment_ = 0;
  jet5_etaphiMoment_ = 0;
  jet6_etaphiMoment_ = 0;
  jet1_phiphiMoment_ = 0;
  jet2_phiphiMoment_ = 0;
  jet3_phiphiMoment_ = 0;
  jet4_phiphiMoment_ = 0;
  jet5_phiphiMoment_ = 0;
  jet6_phiphiMoment_ = 0;
  
  aplanarity_  = 0;
  sphericity_  = 0;
  circularity_ = 0;
  isotropy_ = 0;
  C_ = 0;
  D_ = 0;


  unsigned int jetCounter = 1;
  for(std::vector<pat::Jet>::const_iterator jet = jets.begin(); jet != jets.end(); ++jet, ++jetCounter){

    H_      += jet->energy();
    Ht_     += jet->et();
    Ht3jet_ += jet->et();

    if      (jetCounter == 1) {
      pt1_ = jet->pt();
      Ht3jet_ -= jet->et();
      Ht123_  += jet->et();
      jet1_etaetaMoment_ = jet->etaetaMoment();
      jet1_etaphiMoment_ = jet->etaphiMoment();
      jet1_phiphiMoment_ = jet->phiphiMoment();
    }
    else if (jetCounter == 2) {
      pt2_ = jet->pt();
      Ht3jet_ -= jet->et();
      Ht123_  += jet->et();
      jet2_etaetaMoment_ = jet->etaetaMoment();
      jet2_etaphiMoment_ = jet->etaphiMoment();
      jet2_phiphiMoment_ = jet->phiphiMoment();
    }
    else if (jetCounter == 3) {
      pt3_ = jet->pt();
      Ht123_  += jet->et();
      jet3_etaetaMoment_ = jet->etaetaMoment();
      jet3_etaphiMoment_ = jet->etaphiMoment();
      jet3_phiphiMoment_ = jet->phiphiMoment();
    }
    else if (jetCounter == 4) {
      pt4_ = jet->pt();
      jet4_etaetaMoment_ = jet->etaetaMoment();
      jet4_etaphiMoment_ = jet->etaphiMoment();
      jet4_phiphiMoment_ = jet->phiphiMoment();
    }
    else if (jetCounter == 5) {
      pt5_ = jet->pt();
      jet5_etaetaMoment_ = jet->etaetaMoment();
      jet5_etaphiMoment_ = jet->etaphiMoment();
      jet5_phiphiMoment_ = jet->phiphiMoment();
      Et56_ += jet->et();
    }
    else if (jetCounter == 6) {
      pt6_ = jet->pt();
      jet6_etaetaMoment_ = jet->etaetaMoment();
      jet6_etaphiMoment_ = jet->etaphiMoment();
      jet6_phiphiMoment_ = jet->phiphiMoment();
      Et56_ += jet->et();
    }

    if(jet->bDiscriminator("trackCountingHighPurBJetTags")    > 2.17) ++TCHP_Bjets_;
    if(jet->bDiscriminator("simpleSecondaryVertexBJetTags")   > 2.02) ++SSV_Bjets_;
    if(jet->bDiscriminator("combinedSecondaryVertexBJetTags") > 0.9 ) ++CSV_Bjets_;
    if(jet->bDiscriminator("softMuonBJetTags")                > 0.3 ) ++SM_Bjets_;
  }

  if(jets.size() > 2){

    M3_ = (jets[0].p4() + jets[1].p4() + jets[2].p4()).mass();

    if(jets.size() > 5){
      sqrt_s_ = (jets[0].p4() + jets[1].p4() + jets[2].p4() + jets[3].p4() + jets[4].p4() + jets[5].p4()).mass();
    }
  }

  EventShapeVariables eventshape(makeVecForEventShape(jets));

  aplanarity_  = eventshape.aplanarity();
  sphericity_  = eventshape.sphericity();
  circularity_ = eventshape.circularity();
  isotropy_    = eventshape.isotropy();
  C_           = eventshape.C();
  D_           = eventshape.D();

}

TtFullHadSignalSel::~TtFullHadSignalSel() 
{
}
