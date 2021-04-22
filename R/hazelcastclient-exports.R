
#' Create a HazelcastClient Object from the HazelcastClient C++ Class
#'
#' Allows for the creation of a HazelcastClient Object in _C++_ from _R_
#' using the _C++_ HazelcastClient class.
#'
#' @param name Name of HazelcastClient
#' @param age  Age of HazelcastClient
#' @param male Is HazelcastClient a Male?
#'
#' @return
#' A `HazelcastClient` object from the _C++_ HazelcastClient Class.
#'
#' @examples
#' ##################
#' ## Constructor
#'
#' # Construct new HazelcastClient object called "ben"
#' ben = new(HazelcastClient, name = "Ben", age = 26, male = TRUE)
#'
#' ##################
#' ## Getters
#'
#' ben$LikesBlue()
#'
#' ben$GetAge()
#'
#' ben$IsMale()
#'
#' ben$GetName()
#'
#' ben$GetFavoriteNumbers()
#' @name HazelcastClient
#' @export HazelcastClient

# ^^^^^^^^^^^^^^^^
# Export the "HazelcastClient" C++ class by explicitly requesting HazelcastClient be
# exported via roxygen2's export tag.
# Also, provide a name for the Rd file.


# Load the Rcpp module exposed with RCPP_MODULE( ... ) macro.
loadModule(module = "HazelcastClientEx", TRUE)
