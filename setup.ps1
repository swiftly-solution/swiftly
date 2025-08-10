if (-not $env:GITHUB_SHA) {
    $env:GITHUB_SHA = (git rev-parse HEAD)
}

$env:HL2SDK = "$PSScriptRoot\alliedmodders\hl2sdk-cs2"
$env:MMSOURCE = "$PSScriptRoot\alliedmodders\metamod"

xmake -j 4