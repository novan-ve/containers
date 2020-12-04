#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

check () {

echo -en "$1:\t"
DIFF=$( diff mains/my.txt mains/real.txt )
if [ "$DIFF" != "" ]
then
  echo -e "${RED}[FAIL]${NC}"
  echo "$1" >> output.txt
  echo "$DIFF" >> output.txt
  echo "" >> output.txt
else
  echo -e "${GREEN}[OK]${NC}"
fi
}

rm output.txt 2> /dev/null

if [ $# -eq 0 ]||[ "$1" = "list" ]
then
  # list
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/list_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/list_main.cpp > mains/list_main2.cpp
  #sed -i '13 a \#include \<list\>' mains/list_main2.cpp
  sed -i '' '13a\
#include <list>
' mains/list_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/list_main2.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "List"
  rm mains/list_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi

if [ $# -eq 0 ]||[ "$1" = "vector" ]
then
  # vector
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/vector_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/vector_main.cpp > mains/vector_main2.cpp
#  sed -i '13 a \#include \<vector\>' mains/vector_main2.cpp
  sed -i '' '13a\
#include <vector>
' mains/vector_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/vector_main2.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "Vector"
  rm mains/vector_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi

if [ $# -eq 0 ]||[ "$1" = "stack" ]
then
  # stack
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/stack_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/stack_main.cpp > mains/stack_main2.cpp
#  sed -i '13 a \#include \<stack\>' mains/stack_main2.cpp
  sed -i '' '13a\
#include <stack>
' mains/stack_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/stack_main2.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "Stack"
  rm mains/stack_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi

if [ $# -eq 0 ]||[ "$1" = "queue" ]
then
  # queue
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/queue_main.cpp -o mains/my
  sed 's/ft\:\:/std\:\:/g' mains/queue_main.cpp > mains/queue_main2.cpp
#  sed -i '13 a \#include \<queue\>' mains/queue_main2.cpp
  sed -i '' '13a\
#include <queue>
' mains/queue_main2.cpp
  clang++ -Wall -Werror -Wextra -pedantic -std=c++98 -fsanitize=address mains/queue_main2.cpp -o mains/real
  ./mains/my > mains/my.txt
  ./mains/real > mains/real.txt
  check "Queue"
  rm mains/queue_main2.cpp mains/my mains/real mains/my.txt mains/real.txt
fi
