//  HazelcastClient.h

#ifndef HazelcastClient_H
#define HazelcastClient_H

#include <string>
#include <hazelcast/client/hazelcast_client.h>

class HazelcastClient
{
public:

  // Constructor
  HazelcastClient(std::string ip, std::string clusterName);

  // Getters
  std::string GetTest();

  // Methods
  std::string Get(std::string key);
  void Put(std::string key);


private:

  // Member variables
  std::string url;
  hazelcast::client::hazelcast_client hz;
};

#endif /* HazelcastClient_H */
