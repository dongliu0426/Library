mkdir -p build
FILE="$1"
echo "
#include \"../content/contest/template.cpp\"
#include \"../$FILE\"
" >build/temp.cpp
g++ -std=c++17 -O2 -Wall -Wextra build/temp.cpp && rm a.out build/temp.cpp