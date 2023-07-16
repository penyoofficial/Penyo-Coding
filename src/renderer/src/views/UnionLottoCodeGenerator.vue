<script lang="ts">
import {
  ElRow,
  ElDivider,
  ElButton,
  ElText,
  ElScrollbar,
  ElTimeline,
  ElTimelineItem
} from 'element-plus'
export default {
  name: 'UnionLottoCodeGenerator',
  components: {
    ElRow,
    ElDivider,
    ElButton,
    ElText,
    ElScrollbar,
    ElTimeline,
    ElTimelineItem
  },
  data(): {
    ops: {
      value: string
      timestamp: string
    }[]
  } {
    return {
      ops: []
    }
  },
  methods: {
    newOP() {
      this.ops.unshift({
        value: (() => {
          const rd = (upper: number) => {
            return Math.round(Math.random() * 100) % upper
          }
          const red = new Set<number>(),
            blue = new Set<number>()
          while (red.size < 6) red.add(rd(33) + 1)
          while (blue.size < 1) blue.add(rd(16) + 1)
          const redArr = Array.from(red).sort((a, b) => {
              return a - b
            }),
            blueArr = Array.from(blue)
          let code = ''
          redArr.concat(blueArr).forEach((sc) => {
            code += `${sc}`.padStart(2, '0') + ' '
          })
          return code.replace(/((\d\d ?){6}) (\d\d) /, '$1-$3')
        })(),
        timestamp: (() => {
          const date = new Date()
          const hours = date.getHours().toString().padStart(2, '0')
          const minutes = date.getMinutes().toString().padStart(2, '0')
          const seconds = date.getSeconds().toString().padStart(2, '0')
          return `${hours}:${minutes}:${seconds}`
        })()
      })
    },
    re(fn: Function, times: number) {
      while (times--) fn()
    }
  }
}
</script>

<template>
  <el-row>
    <el-button type="primary" @click="newOP">生成一个</el-button>
    <el-button type="primary" @click="re(newOP, 10)">生成十个</el-button>
    <el-text type="primary" style="margin: 0 3em 0 1em">总数：{{ ops.length }}</el-text>
    <el-button type="warning" @click="ops = []">清空</el-button>
  </el-row>
  <el-divider />
  <el-scrollbar height="366px">
    <el-timeline style="width: 50%; transform: translateX(0.5em)">
      <el-timeline-item
        v-for="op in ops"
        :timestamp="op.timestamp"
        :color="op === ops[0] ? '#0bbd87' : ''"
      >
        {{ op.value }}
      </el-timeline-item>
    </el-timeline>
  </el-scrollbar>
</template>
