/*
  Remove all instances of /* */
*/

void removeComments(char* in, char* out) {

	int countComments = 0;
	int len = strlen(in);
	int j = 0;
	for(int i = 0; i < len-1; i++) {
		if(in[i] == '/' && in[i] == '*') {
			countComments++;
		}
		else if(countComments && in[i] == '*' && in[i] == '/') {
			countComments--;
		}
		else if(countComments) {
			out[j] = in[i];
			j++;
		}
	}
	// Terminate string
	out[j] = '\0';
}