# Speller
Check grammar and spelling with my Speller!

# Author
Stas Dzundza

# How to use?
  - Create object of Speller class;
  - Invoke function __check_text__(const std::string& path_to_dictionary,const std::string& path_to_text,bool check_repeats_of_bad_words = true) of Speller class and put there path to your dictionary, path to your text. Also you can put check_repeats_of_bad_words parametr. True - if you want to check repeats of bad words(less performance), false - if you do not want. By default it is true;
  - You will receive a checking result on the console.
  - __Format of result__: 
  data_structure_name ___ dictionary_loading_time ___ checking time ___ number_of_words_in_text ___number_of_bad_words
 - Bad words will be saved in file __bad_words.txt__
