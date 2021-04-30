// Include Rcpp system header file (e.g. <>)
#include <Rcpp.h>

// Include our definition of the HazelcastClient file (e.g. "")
#include "hazelcastclient.h"

// Expose (some of) the HazelcastClient class
RCPP_MODULE(HazelcastClientEx){
  Rcpp::class_<HazelcastClient>("HazelcastClient")
  .constructor<std::string, std::string, int>()
  .method("SetMap", &HazelcastClient::SetMap)
  .method("Get", &HazelcastClient::Get)
  .method("Put", &HazelcastClient::Put);
}
