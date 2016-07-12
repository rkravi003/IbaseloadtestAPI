@ECHO OFF

set scenario=%1
set resultsDate=%2
set emailTo=%3
set firstName=%4
set lastName=%5


"C:\Program Files (x86)\HP\LoadRunner\bin\Wlrun.exe" -Run -TestPath "C:\Multirunner\ibase_update1\5users_2mins.lrs" -ResultName "C:\Multirunner\ibase_update1\%resultsDate%\%scenario%"

"C:\Program Files (x86)\HP\LoadRunner\bin\AnalysisUI.exe" -RESULTPATH "\\rkravi-t450\LR_Projects\\%resultsDate%\%scenario%\%scenario%.lrr" -TEMPLATENAME catmi2

blat -html -to rkravi@juniper.net %emailTo% -f rkravi@juniper.net -s "Perf Results - %scenario%" -server smtp-out-juniper.net -port 25 -body "DO NOT REPLY TO THIS EMAIL<br />-----------------------<br />Performance Results for:<br /><a href='\\rkravi-t450\LR_Projects\Results\HTMLReports\100SU_02082012.html'>%scenario%</a><br />Started by: <a href='mailto:%emailTo%'>%firstName% %lastName%</a>"

ECHO ^<a href='\\rkravi-t450\LR_Projects\Results\HTMLReports\100SU_02082012.html'^>%scenario%^</a^> started by %firstName% %lastName% on %date% at %time:~0,5% >> "C:\LR_Projects\Automated Test\PerfTestLogs\Reports.txt"


REM or :: are used for commnts