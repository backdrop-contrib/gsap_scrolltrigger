gsap.registerPlugin(ScrollTrigger);

let titles = gsap.utils.toArray(".showonscroll");

// loop through each ".showonscroll" element and create an animation/ScrollTrigger for each
titles.forEach((element, i) => {
  gsap.to(element, {
    opacity: 1,
    ease: "none",
    scrollTrigger: {
      trigger: element,
      start: "top bottom-=10%",
      end: "bottom 60%",
      onEnter: () => {
        gsap.to(element, {
          y: 0,
          duration: 2,
          opacity: 1
        });
      },

      onEnterBack: () => {
        gsap.to(element, {
          y: 0,
          duration: 1,
          opacity: 1
        });
      },
      onLeaveBack: () => {
        gsap.to(element, {
          y: 0,
          duration: 1,
          opacity: 0
        });
      }
    }
  });
});
