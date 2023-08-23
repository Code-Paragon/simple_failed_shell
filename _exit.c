/* handle exit argument */

int exit()
{
	int exit_status;
	
	if (isdigit(*fraginputstr[1]) != 0)
	{
		exit_status = _atoi(fraginputstr[1]);
		exit(exit_status);
	}
	/* exit with 0 if no exit status is passed */
	else
		exit(0);
}
