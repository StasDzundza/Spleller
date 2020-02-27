# Speller
Check grammar and spelling with my Speller!

# Author
Stas Dzundza

# How to use?
  - Create object of Speller class;
  - Invoke function __check_text__(const std::string& path_to_dictionary,const std::string& path_to_text) of Speller class and put there path to your dictionary and path to your text.
  - You will receive a checking result on the console.
  - __Format of result__: 
  data_structure_name ___ dictionary_loading_time ___ checking time ___ number_of_words_in_text ___number_of_bad_words
 - Bad words will be saved in file __bad_words.txt__
