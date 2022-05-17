/**
 * _strlen - prints numbers, followed by a new line
 * @s: is the string to be printed between numbers
 * @flag: is a flag that checks if there is a percentage
 *        entry after the specifier
 * Return: returns length of the string
 */

int _strlen(const char *s, int flag)
{
	int length;

	for (length = 0; *s != '\0'; s++)
		length++;

	if (flag)
		return (length - 1);
	else
		return (length);
}
