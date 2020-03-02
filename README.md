# Speller
Check grammar and spelling with my Speller!

# Author
##Stas Dzundza

# How to compile
You should have compiler which supports c++17 standard, because there uses filesystem header(which was included in c++17);

# How to use?
  - Create object of Speller class;
  - Invoke function __check_text__(const std::string& path_to_dictionary,const std::string& path_to_text) of Speller class and put there path to your dictionary, path to your text.
  - Also you can invoke function __check_texts__(const std::string& path_to_dictionary,const std::string& path_to_dir_with_texts) of Speller class and put there path to your dictionary, path to folder with texts and program will check all texts in this folder.
  - __Format of result__: 
  data_structure_name ___ dictionary_loading_time ___ checking time ___ number_of_words_in_text ___number_of_bad_words
 - Bad words will be saved in file __bad_words.txt__ (Only unique words contain in this file).
   