# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    compare.sh                                         :+:    :+:             #
#                                                      +:+                     #
#    By: novan-ve <novan-ve@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/29 17:08:48 by novan-ve      #+#    #+#                  #
#    Updated: 2020/12/02 15:55:33 by novan-ve      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# list
clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main.cpp -o my
sed 's/ft\:\:/std\:\:/g' list_main.cpp > list_main2.cpp
clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp list_main2.cpp -o real
./my > my.txt
./real > real.txt
diff my.txt real.txt
rm list_main2.cpp my real my.txt real.txt

# vector
clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp vector_main.cpp -o my
sed 's/ft\:\:/std\:\:/g' vector_main.cpp > vector_main2.cpp
clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address main.cpp vector_main2.cpp -o real
./my > my.txt
./real > real.txt
diff my.txt real.txt
rm vector_main2.cpp my real my.txt real.txt
