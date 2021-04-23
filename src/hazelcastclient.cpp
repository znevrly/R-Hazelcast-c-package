//  HazelcastClient.cpp

#include "hazelcastClient.h"


// Constructor
HazelcastClient::HazelcastClient(std::string ip, std::string clusterName) {
  hazelcast::client::client_config config;
  config.set_cluster_name(clusterName);
  config.get_network_config().add_address({ ip, 5701});
  // hz = hazelcast::new_client(std::move(config)).get();
}

// Getters
std::string HazelcastClient::GetTest() { return url; }

// Methods
std::string HazelcastClient::Get(std::string key) {
  return key;
}
