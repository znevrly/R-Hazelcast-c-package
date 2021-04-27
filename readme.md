# Build package (relative path)

    R CMD INSTALL .

# Usage in R

    library(HazelcastClient)
    hz <- new(HazelcastClient, ip = "10.30.100.180", clusterName = "DEV", port = 5701)
    hz$SetMap('mapName') # default map name is 'map'



