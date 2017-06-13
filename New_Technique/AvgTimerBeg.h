
{															
	duration<double> avgTime = duration<double>(0); 		
	for(int avgLoop=0 ; avgLoop<AVG_LOOP_NUM; ++avgLoop){	
		watch.BeginTimer();									
		for(int i=0 ; i<LOOP_NUM ; ++i){					
										
