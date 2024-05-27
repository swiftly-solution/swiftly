$env:MMSOURCE20 = "$PSScriptRoot\alliedmodders\metamod"
$env:HL2SDKCS2 = "$PSScriptRoot\alliedmodders\hl2sdk"
if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

xmake -j ([Environment]::ProcessorCount) -y