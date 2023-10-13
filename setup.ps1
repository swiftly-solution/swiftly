$env:MMSOURCE112 = "C:\Users\SkuZZis\Desktop\CS2 Server\plugins\swiftly\metamod"
$env:HL2SDKCS2 = "C:\Users\SkuZZis\Desktop\CS2 Server\plugins\swiftly\hl2sdk"

mkdir build
Set-Location build
python3 ../configure.py --plugin-name=swiftly --plugin-alias=swift -s cs2 --targets=x86_64
Set-Location ..