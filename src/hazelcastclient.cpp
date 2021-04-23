//  HazelcastClient.cpp

#include "hazelcastClient.h"


// Constructor
HazelcastClient::HazelcastClient(std::string ip, std::string clusterName) : hz(hazelcast::new_client(
            hazelcast::client::client_config().set_cluster_name(clusterName).get_network_config().add_address(
                    {ip, 5701})).get()) {
}


// Getters
std::string HazelcastClient::GetTest() { return url; }

// Methods
std::string HazelcastClient::Get(std::string key) {
  return key;
}
