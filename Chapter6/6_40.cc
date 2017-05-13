

int main() {

  // legal declaration since parameter defaults are on the rightmost side
  int ff(int a, int b = 0, int c = 0);

  // illegal since wd and bckgrd to not have default values
  //char *init(int ht = 24, int wd, char bckgrd);

  return 0;
}