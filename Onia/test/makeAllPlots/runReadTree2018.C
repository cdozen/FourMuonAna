#include "readTree2018.C"
void runReadTree2018()
{
   TChain *chain = new TChain("rootuple/oniaTree","");
//   TChain *chain = new TChain("oniaTree","");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016C.root");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016D.root");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016E.root");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016F.root");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016G.root");
        chain->Add("/eos/uscms/store/user/muahmad/FourMuon_Analysis/NTuples/NTuples_YY/mass_const/2016/Rootuple_Run2016H.root");

   readTree2018 a(chain);
   a.Loop();
}
