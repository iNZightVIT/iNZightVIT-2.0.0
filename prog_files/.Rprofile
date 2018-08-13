## UPDATE iNZightVIT:

VERSION = 1.2

Sys.setenv("R_HOME" = file.path(getwd()))
.libPaths(file.path(getwd(), "library"))

repo <- c("http://r.docker.stat.auckland.ac.nz/R",
          "https://cran.rstudio.com")
options(repos = repo)

## Update modules in the Documents/iNZightVIT/modules directory:
lib <- file.path("~", "iNZightVIT", "modules")
if (file.exists(lib)) .libPaths(lib)

patches <- list.files("../", pattern = "patch$")
if (length(patches) > 0) {
  cat("Updating iNZight from patch file:", patches[1], "\n")
  utils::unzip(sprintf("../%s", patches[1]), exdir = "library")
  cat("\nPatching complete.\n")
  
  Sys.sleep(3)
  q("no")
} else {
  source("https://raw.githubusercontent.com/iNZightVIT/dev/master/update.R")
}
