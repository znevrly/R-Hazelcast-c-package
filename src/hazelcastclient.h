//  HazelcastClient.h

#ifndef HazelcastClient_H
#define HazelcastClient_H

#include <string>
#include <vector>

class HazelcastClient
{
public:

  // Constructor
  HazelcastClient(std::string ip, std::string clusterName);

  // Getters
  int GetTest();

  // Methods
  std::string Get(std::string key);
  void Put(std::string key);


private:

  // Member variables
  std::string url;
};

#endif /* HazelcastClient_H */
