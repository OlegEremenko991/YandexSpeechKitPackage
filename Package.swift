// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "YandexSpeechKitPackage",
    platforms: [.iOS(.v11)],
    products: [
        .library(
            name: "YandexSpeechKit",
            targets: ["YandexSpeechKit"]
        ),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(name: "YandexSpeechKit", path: "./Sources/YandexSpeechKit.xcframework")
    ]
)
