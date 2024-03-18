$env:MMSOURCE112 = "$PSScriptRoot\metamod"
$env:HL2SDKCS2 = "$PSScriptRoot\hl2sdk"
if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

xmake -j 8 -y