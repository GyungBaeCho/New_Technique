		}													
		avgTime += watch.EndTimerNoPrint();				
	}												
}													
avgTime /= AVG_LOOP_NUM;									
cout << "AVG Time : " << to_string(avgTime.count()) << endl << endl;