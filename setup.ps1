$env:MMSOURCE112 = "$PSScriptRoot\metamod"
$env:HL2SDKCS2 = "$PSScriptRoot\hl2sdk"

mkdir build
Set-Location build
python3 ../configure.py --plugin-name=swiftly --plugin-alias=swift -s cs2 --targets=x86_64
Set-Location ..