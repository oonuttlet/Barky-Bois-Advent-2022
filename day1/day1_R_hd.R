#Barky Bois Advent of Code 2022
#Day 1: Hungry Elves
#Harrison DeFord/hdeford1@umbc.edu/@oonuttlet
#spoilers for discord

library(readr)
library(stringr)
library(dplyr)
library(tidyr)

raw <- read_file("input.txt")
raw_split <- lapply(str_split(raw, pattern = "\r\n\r\n"), function(x) str_split(x, pattern = "\r\n"))
raw_split.num <- lapply(raw_split[[1]], function(x) lapply(x, function (y) as.numeric(y)))
raw_split.df <- lapply(raw_split.num, function(x) do.call(cbind, x))

elf_list <- list()
for (i in 1:length(raw_split.df)){
  elf_sum <- rowSums(raw_split.df[[i]], na.rm = TRUE)
  elf_num <- i
  elf_list[[i]]<- cbind.data.frame(elf_num, elf_sum)
}

elf_df <- bind_rows(elf_list)
top_elf_cals <- elf_df %>% arrange(-elf_sum)
top_three_sum <- sum(top_elf_cals[1:3,]$elf_sum)

print(paste0("The top elf is elf ", top_elf_cals[1,1], " who is carrying ", top_elf_cals[1,2], " calories."))
print(paste0("The top three elves are carrying ", top_three_sum, " calories."))
