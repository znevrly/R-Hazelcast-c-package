//  HazelcastClient.cpp

#include "hazelcastClient.h"
#include <hazelcast/client/hazelcast_client.h>


// Constructor
HazelcastClient::HazelcastClient(std::string ip, std::string clusterName) {
  hazelcast::client::client_config config;
  config.set_cluster_name(clusterName);
  config.get_network_config().add_address({ ip, 5701});
  auto con = hazelcast::new_client(std::move(config)).get();
}

// Getters
int HazelcastClient::GetTest() { return 5; }

// Methods
std::string HazelcastClient::Get(std::string key) {
  return key;
}
