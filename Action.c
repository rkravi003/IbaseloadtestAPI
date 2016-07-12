/*********************************************************************
* Project                : Ibase
* File Name              : ibaseupdatedscript.usr
 Description            : 
* Implemented Actions:
* Action() - Added all the requests with which are all in scope of performance testing and commentde which are not in scope                      duplicate check
* Change History
* --------------
* Date	  	Version			Created by	      			Description	
* 08/07/2016  	1.0         Ravikumar G R				Original script

*********************************************************************/
// ibasedetail
// ibasepartner
// ibasewarranty


int iReqMix;
long fileOutHandle;
char logfile[512];
char statusCode[13];
	
  Action()
  {

// 	  sprintf(buf01,"LTEST%s",lr_eval_string("{RanNum}")); lr_save_string(buf01,"uname");
// 	  lr_output_message("login username=%s", lr_eval_string("{uname}"));

 web_add_header("Authorization", "568235ee1cc237000100000109942eb663df4ee66fd7bae3e513ebca");
	  web_set_sockets_option("SSL_VERSION", "TLS");
web_set_sockets_option("OVERLAPPED_SEND", "0");
web_set_sockets_option("IGNORE_PREMATURE_SHUTDOWN", "1");
	  
 
	//iReqMix = 1;
	iReqMix = atoi(lr_eval_string("{ReqMix}"));

	switch(iReqMix)
	{
		
        case 1:
	ibasedetail();
            break;

        case 2:
            ibasepartner();
            break;
    
        case 3:
             ibasewarranty();
            break;


	}
	
    return 0;
}


  //Roles svc
   ibasedetail()
    {
		
//web_reg_find("Search=All",
//        "Text=ibase",
//        LAST);
//	  web_reg_find("Search=All",
//		"Text=[{",
//		LAST);
		
    web_save_header(RESPONSE, "headerVal");
    
        lr_start_transaction(lr_eval_string(lr_eval_string("{MName}")));

        web_custom_request(lr_eval_string(lr_eval_string("{MName}")),
		"URL={purl}ibasedetail/{detailsid}",
		//https://devapigateway.sndbx.junipercloud.net/ibase/rest/ibasedetail/{equipment_id}
        "Method=GET",
        "Resource=1",
        "RecContentType=application/json",
        "Referer=",
        "Snapshot=t1.inf",
        LAST);

        lr_end_transaction(lr_eval_string(lr_eval_string("{MName}")), LR_AUTO);
        strncpy(statusCode, lr_eval_string("{headerVal}"), 12);

	//If response is not HTTP 200
//	lr_save_string(lr_eval_string("C:\\Error\\{MName}_{date}.txt"), "DirPath");
//
//	strncpy(statusCode, lr_eval_string("{headerVal}"), 12);
//
//		if (strcmp(statusCode, "HTTP/1.1 200") == 0)
//		{
//		}
//		else
//		{
//			if (( fileOutHandle = fopen(lr_eval_string("{DirPath}"), "a")) == NULL ) 
//            	{
//					lr_error_message("Cannot open %s", logfile);
//					return -1;
//				} 
//			else 
//				{
//					//lr_output_message("Opened %s", logfile);
//				}
//
//			fprintf( fileOutHandle ,"STATUSCODE = %s\nREQUEST = %s\n-------------------------------------------------\n", statusCode, lr_eval_string("{Request}")); 
//			fclose( fileOutHandle );
//		}

	lr_think_time(1);

    }

   ibasepartner()
{
//web_reg_find("Search=All",
//        "Text=equipment",
//        LAST);
//	web_reg_find("Search=All",
//		"Text=[{",
//		LAST);
		 web_add_header("Authorization", "568235ee1cc237000100000109942eb663df4ee66fd7bae3e513ebca");
		     web_save_header(RESPONSE, "headerVal");
		 
        lr_start_transaction(lr_eval_string(lr_eval_string("{MName}")));

        web_custom_request(lr_eval_string(lr_eval_string("{MName}")),	                
        "URL={purl}ibasepartner/{partnerid}",
        "Method=GET",
        "Resource=1",
        "RecContentType=application/json",
        "Referer=",
        "Snapshot=t2.inf",
        LAST);
    lr_end_transaction(lr_eval_string(lr_eval_string("{MName}")), LR_AUTO);
    strncpy(statusCode, lr_eval_string("{headerVal}"), 12);

	//If response is not HTTP 200
	lr_save_string(lr_eval_string("C:\\Error\\{MName}_{date}.txt"), "DirPath");

	strncpy(statusCode, lr_eval_string("{headerVal}"), 12);

		if (strcmp(statusCode, "HTTP/1.1 200") == 0)
		{
		}
		else
		{
			if (( fileOutHandle = fopen(lr_eval_string("{DirPath}"), "a")) == NULL ) 
            	{
					lr_error_message("Cannot open %s", logfile);
					return -1;
				} 
			else 
				{
					//lr_output_message("Opened %s", logfile);
				}

			fprintf( fileOutHandle ,"STATUSCODE = %s\nREQUEST = %s\n-------------------------------------------------\n", statusCode, lr_eval_string("{Request}")); 
			fclose( fileOutHandle );
		}

	lr_think_time(1);

}

ibasewarranty()
    {
//	web_reg_find("Search=All",
//        "Text=ibase",
//        LAST);
//	web_reg_find("Search=All",
//		"Text=[{",
//		LAST);
		 web_add_header("Authorization", "568235ee1cc237000100000109942eb663df4ee66fd7bae3e513ebca");
		     web_save_header(RESPONSE, "headerVal");
     lr_start_transaction(lr_eval_string(lr_eval_string("{MName}")));

	web_custom_request(lr_eval_string(lr_eval_string("{MName}")),
        "URL={purl}ibasewarranty/{waranty_id}",
        "Method=GET",
        "Resource=1",
        "RecContentType=application/json",
        "Referer=",
        "Snapshot=t3.inf",
        LAST);
    lr_end_transaction(lr_eval_string(lr_eval_string("{MName}")), LR_AUTO);
    strncpy(statusCode, lr_eval_string("{headerVal}"), 12);

	//If response is not HTTP 200
	lr_save_string(lr_eval_string("C:\\Error\\{MName}_{date}.txt"), "DirPath");

	strncpy(statusCode, lr_eval_string("{headerVal}"), 12);

		if (strcmp(statusCode, "HTTP/1.1 200") == 0)
		{
		}
		else
		{
			if (( fileOutHandle = fopen(lr_eval_string("{DirPath}"), "a")) == NULL ) 
            	{
					lr_error_message("Cannot open %s", logfile);
					return -1;
				} 
			else 
				{
					//lr_output_message("Opened %s", logfile);
				}

			fprintf( fileOutHandle ,"STATUSCODE = %s\nREQUEST = %s\n-------------------------------------------------\n", statusCode, lr_eval_string("{Request}")); 
			fclose( fileOutHandle );
		}

	lr_think_time(1);

    }
