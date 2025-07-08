!#/usr/bin/bash
# Exit if any command fails
set -e

# Colors (for pretty output)
GREEN='\033[0;32m'
NC='\033[0m' # no color

echo -e "${GREEN}Cleaning up old builds...${NC}"
rm -f *.o *.a main

echo -e "${GREEN}Compiling ds.c to object file...${NC}"
gcc -c ds/ds.c -o ds.o

echo -e "${GREEN}Creating static library libds.a...${NC}"
ar rcs libds.a ds.o

echo -e "${GREEN}Compiling main.c and linking with libds.a...${NC}"
gcc ds/main.c -L. -lds -o main

echo -e "${GREEN}Build complete! Run with ./main${NC}"