// function to print pink text
void print_pink(char *s)
{
printf("\033[1;35m%s\033[0m", s);
}

// function to print cyan text
void print_cyan(char *s)
{
printf("\033[1;36m%s\033[0m", s);
}

// function to print yellow text
void print_yellow(char *s)
{
printf("\033[1;33m%s\033[0m", s);
}

// function to print blue text
void print_blue(char *s)
{
printf("\033[1;34m%s\033[0m", s);
}

// function to print green text
void print_green(char *s)
{
printf("\033[1;32m%s\033[0m", s);
}

// function to print red text
void print_red(char *s)
{
printf("\033[1;31m%s\033[0m", s);
}

// function to print white text
void print_white(char *s)
{
printf("\033[1;29m%s\033[0m", s);
}

// function to reset the text color to default
void print_reset(char *s)
{
printf("\033[0m%s\033[0m", s);
}
