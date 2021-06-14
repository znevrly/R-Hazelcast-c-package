//  Hazelcastclient.h
#ifndef HazelcastClient_H
#define HazelcastClient_H
#include <string>
#include <hazelcast/client/hazelcast_client.h>

class HazelcastClient
{
public:
  HazelcastClient(std::string ip, std::string clusterName, int port = 5701);

  std::vector<hazelcast::byte> Get(std::string key);
  void Put(std::string key, std::vector<hazelcast::byte> value);
  void SetMap(std::string mapName);
  std::string GetUrl();
  void SetVerboseMode(bool verboseMode); 

private:
  std::string url;
  std::string ip;
  std::string clusterName;
  int port;
  std::string mapName;
  bool verboseMode;
  std::unique_ptr<hazelcast::client::hazelcast_client> hz;
  std::shared_ptr<hazelcast::client::imap> map;
};
#endif /* HazelcastClient_H */