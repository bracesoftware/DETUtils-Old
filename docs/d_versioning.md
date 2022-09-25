# Versioning
- As you've probably seen on the releases page, DETUtils releases follow really complex versioning system. Which is some kind of a mix of semantic versioning and Kalcor's versioning systems.

- My mix of these is named `ser-ver` (because calling it server would be ridiculous) or serial versioning. So this ser-ver consists of 4 numbers named: major update, minor update, version patch and general release of the version.

Not interested? [Go back to the home page...](../README.md)

## Updating the version number
- Updating is easier than you think, so, let's say you've made some nice SA:MP library that you want to publish. If you want to use this **serial versioning** (I will stop calling it ser-ver because it started to sound ridiculous as well), you'd start, or you should start, with **0.0.1-R1** which means your project has zero major updates, zero minor updates, one patch and it is on its first version release.

- Let's say your code had some internal bugs, or your code was messy in general, and you've decided to fix it - you should keep the version number the same, and only increase the release number. So the version would be: **0.0.1-R2**. Which tells the users that no new features were added and that they do not need to upgrade.

- Okay, so your second release of **0.0.1** has been released, yay! Now, let's say you came up with some fascinanting idea for your code, i.e. a new feature. You made it and implemented it. Now you should increase the patch number and set the release number back to **1**. So the version should be **0.0.2-R1**, which immediatelly tells the user that he should update without hesitating and looking at the changelog.

- So, you were enjoying your **0.0.2-R1** and unfortunately found a bug - you got it fixed - what you do? Increase the release number. So: **0.0.2-R2**. Straight to the point.

- Time is passing and you're maintaining your code and you came up to **0.0.9-R1**. What you do? You set the patch number back to zero and release number back to one, and set the minor update number to **1**. So, version of your code is: **0.1.0-R1**. Same is with major updates, once you reach minor update 9, you should not go to 10, but go to major update **1**.

So basically it all goes like this:
- 0.0.1-R1
- 0.0.1-R2 (R2 if you got some bug-fixes and internal/back-end improvements)
- 0.0.2-R1
- 0.0.3-R1
- 0.0.4-R1
...
- 0.0.9-R1
- 0.1.0-R1
- 0.1.1-R1
...
- 0.1.9-R1
- 0.2.0-R1
...
- 0.9.0-R1
- 1.0.0-R1

... and so on.

## Pre-releases
- Imagine that you added some big complicated feature, whose testing is not finished yet then you should add a `-beta` suffix - so your version now is: **0.0.1-R1-beta**. You can change **beta** with something yours of course, such as **alpha**, or **prerelease** or anything!

## Notes

- You're allowed to break backwards compatibility at minor updates.
- Version release numbers aren't limited. Which means that **0.0.1-R52** is completely valid.
