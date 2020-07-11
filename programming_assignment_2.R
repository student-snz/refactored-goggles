makeCacheMatrix <- function(M = matrix())
{
  
  inv_matrix <- NULL
  change_matrix <- function(y) {inv_matrix <<- NULL; M <<- y} # if it is wanted
  set_inv_matrix <- function(inv_M) {inv_matrix <<- inv_M}
  get_matrix <- function() {return(M)}
  get_inv_matrix <- function() {return(inv_matrix)}
  list(change_matrix = change_matrix, set_inv_matrix = set_inv_matrix, get_matrix = get_matrix, get_inv_matrix = get_inv_matrix)
}
cacheSolve <- function(x, ...) {
  #"x" is the object is returned by "makeCacheMatrix"
  Inv <- x$get_inv_matrix()
   if(!is.null(Inv)){
     message("getting cached data")
     return(Inv)
  }
  #else
  Matr <- x$get_matrix()
  Inv <- solve(Matr)
  x$set_inv_matrix(Inv)
  return(Inv)      
}


## x <- matrix(rnorm(16), nrow = 4, ncol = 4)
## x1 <- matrix(rnorm(16), nrow = 4, ncol = 4)
## xx <- makeCacheMatrix(x)
## xx1 <- makeCacheMatrix(x1)

## cacheSolve(xx)
## cacheSolve(xx1)
## cacheSolve(xx1)
## cacheSolve(xx)

