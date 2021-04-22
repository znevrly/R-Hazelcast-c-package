// Include Rcpp system header file (e.g. <>)
#include <Rcpp.h>

// Include our definition of the HazelcastClient file (e.g. "")
#include "HazelcastClient.h"

// Expose (some of) the HazelcastClient class
RCPP_MODULE(HazelcastClientEx){
  Rcpp::class_<HazelcastClient>("HazelcastClient")
  .constructor<std::string, std::string>()
  .method("Get", &HazelcastClient::Get)
  .method("GetTest", &HazelcastClient::GetTest);
}
