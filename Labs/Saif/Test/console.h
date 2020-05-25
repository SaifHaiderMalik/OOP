void setConsoleSize(int cols, int lines)
{
	char consoleT[99];
	
	SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000); //Fullscreen
	
	snprintf(consoleT, sizeof(consoleT), "mode con COLS=%d LINES=%d",cols, lines);
	system(consoleT); // Sets Number of Columns and Rows for the Console
	//system("COLOR F0"); //Sets Background/Foreground Colors
}
